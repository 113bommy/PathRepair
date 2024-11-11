for _ in range(int(input())):
    n = int(input())
    arr = [w for w in input()]
    b = [w for w in input()]
    i = n - 1 
    ans = []
    res = 0 
    while i>=0:
        if arr[0] == b[i]:
            if arr[0]=='1':
                arr[0] = '0'
            else:
                arr[0] = '1'
            ans.append(1)
            p = arr[0:i + 1]
            x = []
            ans.append(i+1)
            for item in p:
                if item=='1':
                    x.append('0')
                else:
                    x.append('1')
            x.reverse()
            arr = x + arr[i+1:]
            res = res + 2 
        else:
            p = arr[0:i + 1]
            x = []
            ans.append(i+1)
            for item in p:
                if item=='1':
                    x.append('0')
                else:
                    x.append('1')
            x.reverse()
            arr = x + arr[i+1:]
            res = res + 1 
        i = i - 1 
    print(res,end=' ')
    for item in ans:
        print(item,end=' ')
    print('')