from sys import stdout, stdin
import io
import os
#input = stdin.readline
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
if __name__ == "__main__":
    n,s = map(int, input().split())
    if s>=2*n:
        stdout.write("YES\n"+"2 "*(n-1)+str(s-(n-1)*2)+"\n1\n")
    else:
        stdout.write("NO")