def task_399A(n, p, k):
    #
    ans = ""
    if p - k > 1:
        ans+="<< "
        for i in range(p-k,p):
            ans+=str(i)
            ans+=" "
    else:
        for i in range(1,p):
            ans+=str(i)
            ans+=" "
    ans+="({:d})".format(p)
    if p + k <n:
        for i in range(p+1,p+k+1):
            ans += " "
            ans+=str(i)
        ans += " >>"
    else:
        for i in range(p+1,n+1):
            ans += " "
            ans+=str(i)
    return ans
def task_399B(n,row):
    val=0
    for c in row:
        val <<= 1
        if c=="B":
            val+=1
    return val
if __name__ == '__main__':
    n= int(input())
    row=input()[::-1]
    print(task_399B(n,row))