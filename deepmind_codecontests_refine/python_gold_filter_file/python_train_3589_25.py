from math import gcd
n,m = list(map(int,input().split()))
x = 10**5
boys = list(map(int,input().split()))
girls = list(map(int,input().split()))
v1 = [False for i in range(n)]
v2 = [False for i in range(m)]
for i in boys[1::]:
    v1[i] = True
for i in girls[1::]:
    v2[i] = True
for i in range(x):
    a,b = i%n,i%m
    if v1[a]==True or v2[b]==True:
        v1[a] = True
        v2[b] = True
# print(v1)
# print(v2)
if False in v1 or False in v2:
    print("No")
else:
    print("Yes")