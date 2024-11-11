s = input().split()

n = 0
arr = []
op = []
for i in s:
    if (i=='='):
        break
    if (i=='+'):
        op.append(1)
    elif (i=='-'):
        op.append(-1)
    else :
        arr.append(1)
n = int(s[-1])

val = arr[0]
for i in range(len(op)):
    val += op[i]*arr[i+1]
    
if (val<n):
    rem = n - val
    for i in range(len(arr)):
        if ( i!=0 and op[i-1]==-1):
            continue
        up = min(rem, n-arr[i])
        arr[i] += up
        rem -= up
        if (rem == 0):
            break
    if (rem!=0):
        print("Impossible")
        exit(0)
elif (val>n):
    rem = val - n
    for i in range(len(arr)):
        if ( i==0 or op[i-1]==1):
            continue
        up = min(rem, n-arr[i])
        arr[i] += up
        rem -= up
        if (rem == 0):
            break
    if (rem!=0):
        print("Impossible")
        exit(0)
    
print("Possible")
tos = str(arr[0]) + " "

for i in range(len(op)):
    if (op[i]==-1):
        tos += "- "
    else:
        tos += "+ "
    
    tos += str(arr[i+1]) + " "
    
tos += "= "+str(n)    


print(tos)