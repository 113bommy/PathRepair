inp = input()
out = ""
extra = input()
s = inp.split("|")
n = len(extra)
# print(s)
left = len(s[0])
right = len(s[1])
if left == right and n % 2 == 1:
    print("Impossible")
elif abs(left - right) > n:
    print("Impossible")
else:
    diff = abs(left - right)
    if (n - diff) % 2 == 1:
        print("Impossible")
    else:
        if left > right:
            s[1] += extra[:diff]
        else:
            s[0] += extra[:diff]
        for i in range(diff, n):
            if i % 2 == 1:
                s[1] += extra[i]
            else:
                s[0] += extra[i]
        print("|".join(s))