s = input().split()
k = int(s[0])
a = int(s[1])
b = int(s[2])

c = (str(input()))

if ((len(c) < k*a) or (len(c) > k*b)):
    print("No solution")
else:
    lengths = []
    for i in range (k):
        lengths.append(len(c)//k)
    for i in range (len(c) % k):
        lengths[i] += 1
    prev = 0
    ans = []
    id = 0
    for x in lengths:
        ans.append(c[prev:prev+x])
        prev += x
    for x in ans:
        print(x)