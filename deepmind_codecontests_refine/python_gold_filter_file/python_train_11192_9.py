def solve(n,m,d,e):
    big = float('inf')
    small = float('-inf')
    d.sort()
    res = []
    for i in e:
        if i >= d[-1]:            
            res.append(n)
            continue
        low = 0
        high = n - 1
        mid = (low + high) // 2
        flag = True        
        while(low < high):
            mid = (low + high) // 2
            # print(low,mid,high)
            if d[mid] <= i < d[mid + 1]:
                res.append(mid + 1)
                flag = False
                break
            elif d[mid] <= i:
                low = mid + 1
            else:
                high = mid 
        if flag:
            res.append(mid)
    return res


def main():
    # t = int(input())    
# for i in range(t):
    t = input()
    t = [int(i) for i in t.split()]
    n = t[0]
    m = t[1]
    d = input()
    d = [int(i) for i in d.split()]       
    e = input()
    e = [int(i) for i in e.split()]  
    ans = solve(n,m,d,e) 
    # print(ans)     
    for i in ans:
        print(i,end = " ")
    print()  
main()
n = 5 
m = 1
a = [1,3,5,7,9]# 7 9
b = [6, 4, 2, 8]
# print(solve(n,m,a,b))