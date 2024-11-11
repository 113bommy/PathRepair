n = int (input())
answer = 0
arr = input().split()
a,b = map(int , input().split())
for i in range(a-1,b-1): 
    answer+=int(arr[i])
print(answer)

    