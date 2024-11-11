def main():
    n = int(input())
    a = list(map(int, input().split()))
    answer = 0
    for i in range(n):
        cur_ans = 0
        prefix = [0]*(n - i)
        prefix[0] = a[i]
        if n - i > 1:
            for j in range(n - i):
                prefix[j] = prefix[j - 1] + a[j + i]
        mul = 1
        for j in prefix:
            if j > 100*mul: 
                cur_ans = j//100
            mul += 1
        answer = max(answer, cur_ans,)
    answer = min(answer, n)
    print(answer)
if __name__=="__main__":
    main()