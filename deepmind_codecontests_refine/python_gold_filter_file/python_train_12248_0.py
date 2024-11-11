def main():
    n,a,b = map(int,input().split())
    found = False
    for x in range(n+1):
        rem = n-a*x
        if rem >= 0 and rem%b == 0:
            y = rem//b
            found = True
            break
        
    if not found:
        print(-1)
        return

    ans = []
    if a == 1 or b == 1:
        for i in range(n):
            ans.append(i+1)
    else:
        start = 1
        for i in range(x):
            arr = [start+1]
            for j in range(a-2):
                arr.append(arr[-1]+1)

            arr.append(start)
            start = arr[-2]+1
            ans.extend(arr)

        for i in range(y):
            arr = [start+1]
            for j in range(b-2):
                arr.append(arr[-1]+1)

            arr.append(start)
            start = arr[-2]+1
            ans.extend(arr)
        
    for i in ans:
        print(i,end = ' ')

main()
