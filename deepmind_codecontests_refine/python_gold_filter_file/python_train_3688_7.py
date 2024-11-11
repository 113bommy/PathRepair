b=0
w=int(input())
maxyear=0
n=list(map(int,input().split()))[:w]
a,b=map(int,input().split())
d=(b-1)
for j in range((a-1),d):
    maxyear+=n[j]
print(maxyear)