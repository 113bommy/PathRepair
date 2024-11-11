def str_inp(n):
    return [[i,input()] for i,x in enumerate(range(n))]

def get_col(arr, i):
    return [row[i] for row in arr]

for i in range(int(input())):

    dic, ans = dict({j: False for j in range(10)}), 0
    arr = str_inp(int(input()))
    arr.sort(key=lambda x:x[1])

    for j in get_col(arr,1):
        dic[int(j[0])] = True

    new = [[arr[0][0],arr[0][1]]]

    for j in range(1, len(arr)):
        tem = arr[j][1]
        if arr[j][1] == arr[j - 1][1]:
            ans += 1
            for k1, k2 in dic.items():
                if not dic[k1]:
                    tem = arr[j][1].replace(arr[j][1][0], str(k1),1)
                    dic[k1] = True
                    break
        new.append([arr[j][0],tem])

    new.sort(key=lambda x:x[0])
    print(ans)
    print(*get_col(new,1), sep='\n')
