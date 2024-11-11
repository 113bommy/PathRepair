# @oj: codeforces
# @id: hitwanyang
# @email: 296866643@qq.com
# @date: 2020-10-30 16:42
# @url:https://codeforc.es/contest/1108/problem/D
import sys,os
from io import BytesIO, IOBase
import collections,itertools,bisect,heapq,math,string
from decimal import *
# region fastio

BUFSIZE = 8192

BUFSIZE = 8192

class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
# ------------------------------
## 注意嵌套括号!!!!!!
## 先有思路,再写代码,别着急!!!
## 先有朴素解法,不要有思维定式,试着换思路解决
## 精度 print("%.10f" % ans)
## sqrt:int(math.sqrt(n))+1
## 字符串拼接不要用+操作，会超时
## 二进制转换:bin(1)[2:].rjust(32,'0')
## array copy:cur=array[::]
## oeis:example 1, 3, _, 1260, _, _, _, _, _, 12164510040883200
def main():
    n=int(input())
    s=str(input())
    l,r=0,0
    res=[]
    while r<n:
        while r<n and s[l]==s[r]:
            r+=1
        res.append((r-l,s[l]))
        l=r
    t=[]
    pos=0
    for r in res:
        pos+=r[0]
        if r[0]>1:
            if r[0]%2==0:
                cnt=r[0]//2
                while cnt>0:
                    t.append(pos-1-(cnt-1)*2)
                    cnt-=1
            else:
                cnt=r[0]//2
                while cnt>0:
                    t.append(pos-2-(cnt-1)*2)
                    cnt-=1
        # ans+=r[0]//2
    # print (t)
    print (len(t))
    ans=list(s)
    rgb=['R','G','B']
    for j in t:
        for x in rgb:
            ans[j]=x
            if j==n-1 and ans[j-1]!=x:
                break
            if j!=n-1 and ans[j-1]!=x and ans[j+1]!=x:
                break
    print ("".join(ans))
if __name__ == "__main__":
    main()