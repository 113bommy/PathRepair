n = int(input())
a = list(input())
o = n
h = False

for i in range(n - 1):
    if h is False and (a[i] + a[i + 1] == "RU" or a[i] + a[i + 1] == "UR"):
        o -= 1
        h = True

    else:
        h = False

print(o)
