import sys
input = sys.stdin.readline
def multi_input():
    return map(int, input().split())

def array_print(arr):
    print(' '.join(map(str, arr)))


n, k = multi_input()
a = list(multi_input())
min1 = 100005
sum = 0
for i in range(n):
    if a[i]<0 and k>0:
        a[i] *= -1
        k -= 1
    if min1 > a[i]:
        min1 = a[i]
    sum += a[i]

if k%2==1:
    ans = sum - 2*min1
else:
    ans = sum

print(ans)
