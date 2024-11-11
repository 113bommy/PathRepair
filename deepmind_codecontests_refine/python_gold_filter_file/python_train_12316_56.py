from sys import stdin

k = int(stdin.readline().rstrip())
l = int(stdin.readline().rstrip())
m = int(stdin.readline().rstrip())
n = int(stdin.readline().rstrip())
d = int(stdin.readline().rstrip())

counter=0
for ci in range(1, d+1):
    if (d>=k and ci%k==0) or (d>=l and ci%l==0) or (d>=m and ci%m==0) or (d>=n and ci%n==0):
        counter+=1

print(counter)
