sr=lambda: input()
ir=lambda: int(sr())
lr=lambda: list(map(int, sr().split()))

inf = 10**18
# mod = 10**9+7
mod = 998244353

if __name__=='__main__':
    test = ir()
    for t in range(test):
        n,k,x = lr()
        a=sr()
        count = []
        pre = ''
        now = 0
        start_inds = []
        for c in a:
            if c == '*':
                if pre == '*':
                    now+=1
                else:
                    now=1
            else:
                if now > 0:
                    count.append(now*k+1)
                now = 0
            pre = c
        if now>0 and pre == '*':
            count.append(now*k+1)
        count.reverse()
        count_per = [1]
        x-=1
        start = 0
        for ind, num in enumerate(count[:-1]):
            count_per.append(num*count_per[-1])
            if count_per[-1] > 10**18:
                start = len(count)-1-ind
                count_per.pop()
                break
        for i in range(start):
            count.pop()

        count.reverse()
        count_per.reverse()

        nums = []
        ret = x
        for num in count_per:
            tmp = ret//num
            nums.append(tmp)
            ret = ret%num

        ans = []
        now_count = 0
        now = 0
        for c in a:
            if c=='*':
                if pre=='*':
                    now+=1
                else:
                    now=1
            else:
                if now > 0:
                    if now_count >= start:
                        ind = now_count-start
                        for _ in range(nums[ind]):
                            ans.append('b')
                    now_count+=1
                ans.append('a')
                now = 0
            pre=c
        if pre=='*':
            if now_count >= start:
                ind = now_count-start
                for _ in range(nums[ind]):
                    ans.append('b')
            now_count+=1
        print(*ans, sep="")