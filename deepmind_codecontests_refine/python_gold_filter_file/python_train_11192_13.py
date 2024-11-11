from bisect import bisect_right


s = str(input())
z=lambda:map(int,input().split())
k=z()
mas1=list(k)
z=lambda:map(int,input().split())
k=z()
mas2=list(k)
mas1=sorted(mas1)



for i in mas2:
    print(bisect_right(mas1,i),end=" ")