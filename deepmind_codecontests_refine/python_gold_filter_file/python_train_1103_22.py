def find_min_char(k: int, n: str) -> int:
    chars = list(n)
    int_list = list(map(int, chars))
    true_k = sum(int_list)
    int_list.sort()
    need_inc = k - true_k
    min_char = 0
    for i in int_list:
        if need_inc <= 0:
            return min_char
        min_char += 1
        need_inc -= 9 - i
    return min_char


if __name__ == '__main__':
    k = int(input())
    n = str(input())
    result = find_min_char(k, n)
    print(result)
