problem_num = int(input())
for i in range(problem_num):
    n,k = input().split()
    n = int(n);k=int(k)
    arr = input().split()
    arr = [int(i) for i in arr]
    arr.sort()
    sub_main = arr[:n-2*k]
    sub_div = arr[n-2*k:]
    sub_score = 0
    for j in range(k):
        sub_score += int(sub_div[j]/sub_div[k+j])
    score = sum(sub_main) + sub_score
    print(score)