"""
AC|T
L

|ABC
XYZ

W|T
F

"""
w = input()
o = input()
left, right = w.split("|")
minW = min(len(left), len(right))
maxW = max(len(left), len(right))

if (len(left) + len(right) + len(o)) % 2 != 0 or (minW + len(o)) < maxW:
    print("Impossible")
else:
    if (len(w) - 1 + len(o)) % 2 == 0:
        while o:
            if len(left) > len(right):
                right += o[0]
            else:
                left += o[0]
            o = o[1:]
    print(left + "|" + right)
