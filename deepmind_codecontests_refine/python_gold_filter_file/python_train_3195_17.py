n = int(input()) + 1
row = str(input())

row = list("0" + row + "0")


def check_arr(arr, n):
    ok = True
    for i in range(1, n):
        if arr[i] == "1":
            if arr[i - 1] != "0" or arr[i + 1] != "0":
                ok = False
                break
    return ok


if check_arr(row, n):
    ok2 = True
    for i in range(1, n):
        if row[i] == "0":
            row[i] = "1"
            if check_arr(row, n):
                ok2 = False
                break
            row[i] = "0"
    if ok2:
        print("Yes")
    else:
        print("No")

else:
    print("No")
