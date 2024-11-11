#
# from functools import reduce
st = input()
m = len(st)
# print(st[1],m)

res = []

# print(arr)
for i in range(m):
    arr = ["-"] * 8
    n = int(st[i])
    arr[2] = "|"
    if(n >= 5):
        arr[1] = "O"
        x = n-5
        if x == 0:
            arr[4:] = ["O"] * 4
        else:
            arr[3:3 + x] = ["O"] * x
            arr[3 + x] = "-"
            arr[3 + x + 1:] = ["O"] * (4 - x)
    else:
        arr[0] = "O"
        x = n
        if x == 0:
            arr[4:] = ["O"]*4
        else:
            arr[3:3+x]=["O"]*x
            arr[3+x] = "-"
            arr[3+x+1:] = ["O"]*(4-x)
    res.append(''.join(x for x in arr))
for i in range(m):
    print(res[m-i-1])
# print(arr)

#
#
#
#
#
# a = [1,2,3,4,5]
# a[1:] = [7]*len(a[1:])
# print(a)