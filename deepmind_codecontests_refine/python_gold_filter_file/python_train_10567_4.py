s = input()
shifts = int(input())

for i in range(shifts):
    l, r, k = map(int, input().split())
    k = k % (r - l + 1)
    s = s[:l - 1] + s[r - k:r] + s[l - 1:r - k] + s[r:]
print(s)