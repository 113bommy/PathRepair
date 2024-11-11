# a=[1,2,3,4]
# d=2
# right = a[d::]
# left = a[:d:]
# a = right+left
# print(a)
def leftshift(a,d):
    right = a[d::]
    left = a[:d:]
    a = right + left
    # print(a)
    return a

for t in range(int(input())):
    n = int(input())
    a =list(map(int,input().split()))
    c = a.copy()
    c.sort()
    ans=[]
    count=0
    dic={}
    for i in range(n):
        dic[a[i]] = i

    for i in range(n):
        tem = c[i]
        act_i = dic[tem]
        req_i = i
        if act_i==req_i:
            continue
        else:
            count+=1
            d = abs(req_i-act_i)
            # print(d)
            a_tem = a[i:]
            a_old = a[:i]

            # print(a_old,a_tem)
            a_rem = leftshift(a_tem,d)
            a=a_old + a_rem
            # print(a,'concatenated')
            ans.append([i + 1, n,d])
            for i in range(n):
                dic[a[i]] = i

            if a==c:
                break
    print(count)
    for i in ans:
        print(*i)