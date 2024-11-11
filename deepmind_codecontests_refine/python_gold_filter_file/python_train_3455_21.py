n,k = map(int,input().split())
narr = list(input())
if len(narr) == 1 and k==1:
    print("0")
else:
    for i in range(len(narr)):
        if k == 0:
            break
        else:
            if (narr[i] == "0") or (narr[i] == "1" and i == 0):
                continue
            narr[i] = "1" if i == 0 else "0"
            k -= 1
    print("".join(narr))