def gen(l, r):
    global ans
    if sum(a[l - 1:r]):
        ans += [[l, r]]
        return
    if r == l: fail()
    for i in range(l, r):
        if a[i - 1]:
            gen(l, i)
            gen(i + 1, r)
            return
    fail()
def fail():
    print('NO')
    quit()
n = int(input())
a = list(map(int, input().split()))
ans = []
gen(1, n)
ans.sort()
print('YES')
print(len(ans))
for l, r in ans:
    print(l, r)