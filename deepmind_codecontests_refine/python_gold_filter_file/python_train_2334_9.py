import sys
import bisect
from collections import Counter,defaultdict as dd
def data(): return sys.stdin.readline().strip()
def out(var): sys.stdout.write(str(var))
def l(): return list(sp())
def strl(): return list(strsp())
def sp(): return map(int, data().split())
def strsp(): return map(str, data().split())

n=int(data())
a=[]
for i in range(4):
    a.append(list(data()))
b=[0]*(10)
# b[0]+=a[0].count('.')+a[1].count('.')+a[2].count('.')+a[3].count('.')
b[1]+=a[0].count('1')+a[1].count('1')+a[2].count('1')+a[3].count('1')
b[2]+=a[0].count('2')+a[1].count('2')+a[2].count('2')+a[3].count('2')
b[3]+=a[0].count('3')+a[1].count('3')+a[2].count('3')+a[3].count('3')
b[4]+=a[0].count('4')+a[1].count('4')+a[2].count('4')+a[3].count('4')
b[5]+=a[0].count('5')+a[1].count('5')+a[2].count('5')+a[3].count('5')
b[6]+=a[0].count('6')+a[1].count('6')+a[2].count('6')+a[3].count('6')
b[7]+=a[0].count('7')+a[1].count('7')+a[2].count('7')+a[3].count('7')
b[8]+=a[0].count('8')+a[1].count('8')+a[2].count('8')+a[3].count('8')
b[9]+=a[0].count('9')+a[1].count('9')+a[2].count('9')+a[3].count('9')
m=max(b)
if(m > 2*n):
    print("NO")
else:
    print("YES")