import io
import os
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
def solve():
    n,x=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort(reverse=True)
    su=d=0
    for i in range(n):
        if a[i]>x:
            su+=a[i]-x
        elif a[i]<x:
            if su-(x-a[i])<0:
                break
            else:
                su=su-(x-a[i])
        d=i+1
    print(d)
def main():
    for t in range(int(input())):
        solve()
if __name__=="__main__":
    main()