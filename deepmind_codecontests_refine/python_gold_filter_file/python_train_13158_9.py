import itertools

n, k = map(int, input().split())
values = [int(i) for i in input().split()]
psa = [0] + list(itertools.accumulate(values))
best_real_sum, best_real_indexa, best_real_indexb, best_partial_sum, best_partial_indexa = -1, -1, -1, -1, -1
for i in range(n - 2 * k , -1, -1): # account for best starting from right
    partial_sum = psa[i + 2 * k] - psa[i + k]
    if partial_sum >= best_partial_sum:
        best_partial_sum = partial_sum
        best_partial_index = i + k
    real_sum = psa[i + k] - psa[i]
    if real_sum + best_partial_sum >= best_real_sum:
        best_real_sum = real_sum + best_partial_sum
        best_real_indexa, best_real_indexb = i, best_partial_index
print(best_real_indexa + 1, best_real_indexb + 1)
