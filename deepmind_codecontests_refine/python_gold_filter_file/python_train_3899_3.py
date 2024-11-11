import collections
def main():
    hash_sum = collections.defaultdict(int)
    sum = 0
    n,v = map(int,(input().split()))
    for i in range(n):
        a, b = map(int, (input().split()))
        hash_sum[a] += b
    for i in range(1,3002):
        current = hash_sum[i]

        prev = hash_sum[i-1]
        taken = min(v , prev)
        hash_sum[i-1] -= taken
        sum += taken

        taken = min((v-taken), current)
        hash_sum[i] -= taken
        sum += taken

    return sum

result = main()
print(result)