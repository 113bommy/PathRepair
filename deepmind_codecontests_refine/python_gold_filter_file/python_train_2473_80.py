n=int(input())
l=sorted(list(map(int,input().split())))
if(n%2!=0):
    print(l[n//2])
else:
    print(l[(n//2)-1])
