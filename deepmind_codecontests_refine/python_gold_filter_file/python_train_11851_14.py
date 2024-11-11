def main():
    n=int(input())
    if n==3:
        print(2,5,63)
        return 0
    ans=[2,3]
    cnt=0
    i=10
    while cnt<n-4:
        if i%2==0 or i%3==0:
            ans.append(i)
            cnt+=1
        i+=1
    a=sum(ans)
    if n==20000:
        ans.pop()
        ans.pop()
        ans.append(8)
        ans.append(9)
    elif n==19999:
        ans.pop()
        ans.append(8)
    if a%6==0:
        ans.append(4)
        ans.append(8)
    elif a%6==1:
        ans.append(8)
        ans.append(9)
    elif a%6==2:
        ans.append(4)
        ans.append(6)
    elif a%6==3:
        ans.append(6)
        ans.append(9)
    elif a%6==4:
        ans.append(8)
        ans.append(6)
    elif a%6==5:
        ans.append(9)
        ans.append(4)
    print(*ans)
main()