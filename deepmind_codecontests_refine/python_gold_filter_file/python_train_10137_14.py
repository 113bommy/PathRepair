n = int(input())
a = list(input())

index = 0
ans = []
for i in range(len(a)//2):
    if i == (len(a)//2-1):
        ans.append(''.join(a[index:index+3]))
        break
    ans.append(''.join(a[index:index+2]))
    index += 2
print('-'.join(ans))