n = int(input())
s = [int(i) for i in input().split()]
s.sort()
counter = 0
for i in range(n):
    if s[i]>=counter+1:
        counter+=1
print(counter)