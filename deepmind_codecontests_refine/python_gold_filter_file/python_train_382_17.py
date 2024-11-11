n = int(input())
L = list(map(int,input().split()))
L.sort()
z1 = 1
z2 = 2
s0 = 0
s1 = 0
for i in L:
    s0+=abs(i-z1)
    s1+=abs(i-z2)
    z1+=2
    z2+=2
    #print(s0,s1)
print(min(s0,s1))
