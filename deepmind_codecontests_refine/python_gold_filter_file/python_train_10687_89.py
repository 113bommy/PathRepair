inp = input().split()
n = int(inp[0])
k = int(inp[1])
#print(n // 10)
for i in range(0,k):
    if((n % 10) != 0):
        n = n - 1
        k = k - 1
        #print("n is" , n , "in k is ", k)
    else:
        n = n // 10
        k = k - 1
        #print("n is in else with value n = " , n , "in k is ", k)
print(n)

