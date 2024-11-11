n, m = [int(x) for x in input().strip().split(" ")]
a = "5"
b = "5"
while (len(a) * 5 < n or (len(b)-1)*4 + 5 < n):
    a = "5" + a
    b = "4" + b
print(a, b)
