from sys import stdin

n, k = [int(i) for i in stdin.readline().strip().split()]
s = stdin.readline().strip()


def get_f(s):
    F = [len(s) * [0] for _ in range((len(s) + 1))]
    size = 0
    for index in range(len(s)):
        F[size][index] = 1
    F[1][0] = 1

    p = {s[0]: 0}
    for i in range(1, len(s)):
        for k in range(1, len(s) + 1):
            if k > i + 1:
                val = 0
            else:
                val = F[k][i - 1] + F[k - 1][i - 1]
                if s[i] in p:
                    # sic: if k - 1 == 0 then answer is always 1
                    if k - 1 == 0:
                        val -= 1
                    elif p[s[i]] - 1 >= 0:
                        val -= F[k - 1][p[s[i]] - 1]
            F[k][i] = val
        p[s[i]] = i
    return F

_F = get_f(s)

# for sz in range(len(s) + 1):
#     for index in range(len(s)):
#         print(_F[sz][index], end=' ')
#     print()


def count(size, index = None):
    return _F[size][index or (len(s) - 1)]


# recursive solution with memoization
previous_letter_index = {}
found = {}
for index, letter in enumerate(s):
    if letter in found:
        previous_letter_index[(letter, index)] = found[letter]
    found[letter] = index

_subsequences = {}


def subsequences(size, index):
    """Get number of distinct subsequences of given size in sequence[0:index + 1] slice"""
    if (size, index) not in _subsequences:
        if size == 0:
            res = 1
        elif size > index + 1:
            res = 0
        else:
            res = subsequences(size, index - 1) + subsequences(size - 1, index - 1)
            letter = s[index]
            if (letter, index) in previous_letter_index:
                res -= subsequences(size - 1, previous_letter_index[(letter, index)] - 1)
        _subsequences[(size, index)] = res
    return _subsequences[(size, index)]


total_cost = 0
for size in range(len(s), -1, -1):
    if k == 0:
        break
    step_cost = n - size
    sequence_count = count(size, len(s) - 1)
    # print('size = ', size, 'count = ', sequence_count)
    if sequence_count > k:
        sequence_count = k
    total_cost += step_cost * sequence_count
    k -= sequence_count

if k == 0:
    print(total_cost)
else:
    print(-1)
