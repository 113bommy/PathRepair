
n = int(input())
a = [int(x) for x in str(input()).strip().split(" ")]
half_sum = sum(a)/2
solved = 0
for i in range(1, n+1):
    solved += a[i-1]
    if solved >= half_sum:
        print(i)
        break
