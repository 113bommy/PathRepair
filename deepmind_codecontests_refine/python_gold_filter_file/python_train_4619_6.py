n = int(input())
c = 0
for i in range(n):
    s = input().replace('0', '').replace(' ', '')
    if len(s) >= 2:
        c +=1
print(c)
