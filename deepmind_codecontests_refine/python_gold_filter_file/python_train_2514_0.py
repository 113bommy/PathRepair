len1 = eval(input())
num = input()
f = input()
a = f.split(' ')
f = ['0']
for i in a:
    f.append(i)
max = int(num)
ans = ''
begin = 0
for i in range(0, len1):
    if(int(f[int(num[i])]) > int(num[i])):
        begin = i
        ans += num[0:i]
        break

for x in range(begin, len1):
    if (int(f[int(num[x])]) >= int(num[x])):
        ans += f[int(num[x])]
    else:
        ans += num[x:]
        break
print(ans)
