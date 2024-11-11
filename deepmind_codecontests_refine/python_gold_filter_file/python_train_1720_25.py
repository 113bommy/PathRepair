def bsearch(left,right,value):
    k = left + right
    k//=2
    if (left-right) == -1:
            return left
    if ((k*(k+1))//2 >= value):
        return bsearch(left,k,value)
    else:
        return bsearch(k,right,value)
n = int(input())
max_val = int(1e9)
min_val = 0
t = bsearch(min_val,max_val,n)
q = (t*(t+1)//2)
print(str(n-q))