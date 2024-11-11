n = int(input())
a = list(map(int, input().split()))
def final(ans):
    print(len(ans))
    for i in range(len(ans)):
        print(*ans[i])
if a == ([0] * n):
    print("NO")
    exit(0)
print("YES")
ans = []
last = -1
for i in range(n):
    if (a[i] != 0):
        last = i
        break
if (last == n - 1):
    ans.append([1, n])
    final(ans)
    exit()
mmm = -1
for i in range(last + 1, n):
    if (a[i] != 0):
        ans.append([1, i])
        mmm = i
        break
if (mmm == -1):
    ans.append([1, n])
    final(ans)
    exit()
last = mmm
left = last
right = last + 1
flag = last
while right < n:
    if (a[right] != 0):
        ans.append([left + 1, right])
        #print(left + 1, right)
        left = right
        flag = right
    right += 1
if flag != n:
    ans.append([left + 1, n])
final(ans)
