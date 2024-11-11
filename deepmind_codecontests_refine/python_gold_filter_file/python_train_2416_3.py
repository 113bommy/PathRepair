t = int(input())
for _ in range(t):
    n = int(input())
    arr = []
    for i in range(n):
        arr.append(input())
    ar = set(arr)
    print(n - len(ar))
    new_arr = []
    
    for i in arr:
        if i not in new_arr:
            new_arr.append(i)
        else:
            for j in range(10):
                val = str(j) + i[1:]
                if val not in ar:
                    ar.add(val)
                    new_arr.append(val)
                    break
    print("\n".join(new_arr))