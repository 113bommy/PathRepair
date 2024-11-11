n = int(input())
a = [int(i) for i in input().split()]
a = sorted(a)
count = 0
problems=1
for i in range(0,len(a)):
    if a[i] >= problems:
        count += 1
        problems+=1
    else:
        continue
print(count)
