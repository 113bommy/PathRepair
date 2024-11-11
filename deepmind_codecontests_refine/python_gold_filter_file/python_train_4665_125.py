n=int(input())//2
l=sorted(list(map(int,input().split())))
print(l[n]-l[n-1])