n, k = map(int, input().split())
a = [int(i) for i in input().split()]

sums = []
su = sum(a[:k - 1])
for i in range(n - k + 1):
    su += a[i + k - 1]
    if (i > 0):
        su -= a[i - 1]
    sums.append(su)

max_first = 0
first = 0
second = k
su = a[first] + a[second]
for i in range(n - 2 * k + 1):
    sum1 = sums[i] + sums[i + k]
    sum2 = sums[first] + sums[i + k]
    sum3 = sums[max_first] + sums[i + k]
    if (sum2 > su):
        second = i + k
        su = sum2
    if (sum3 > su):
        first = max_first
        second = i + k
        su = sum3
    if (sum1 > su):
        first = i
        second = i + k
        su = sum1
    if (sums[i] > sums[max_first]):
        max_first = i
print (first + 1, second + 1)