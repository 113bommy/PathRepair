n = int(input())


e = [int(i)-1 for i in input().split()]
v = [int(i) for i in input().split()]
counter = 1

for i in range(n-1):
    if v[e[i]] != v[i+1]:
        counter+=1
        
print(counter)