n=int(input())
l=sorted(list(map(int,input().split())))
print(l[n//2]-l[n//2-1])