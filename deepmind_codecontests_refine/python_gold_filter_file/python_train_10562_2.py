n, m = list(map(int, input().split()))
arr = list(input())
arr2 = list(input())
k = f'{arr[0]}{arr2[-1]}{arr[-1]}{arr2[0]}'
#print(k)
if k == '>v<^' or k == '<^>v':
    print("YES")
else:
    print("NO")