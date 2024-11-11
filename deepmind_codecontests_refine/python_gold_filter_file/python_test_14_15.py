def is_sorted(seq):
    for x in range(len(seq) - 1):
        if seq[x] > seq[x + 1]:
            return False
    return True


if __name__ == '__main__':
    for _ in range(int(input())):
        input()
        values = list(map(int, input().split()))
        n = len(values)

        ops = []
        for sp in range(n):
            min_val, min_index = values[sp], sp
            if is_sorted(values):
                break
            for x in range(sp, n):
                if values[x] < min_val:
                    min_val = values[x]
                    min_index = x
            if min_index == sp:
                continue
            ops.append((sp + 1, n, min_index - sp))
            values = values[:sp] + values[min_index:] + values[sp:min_index]
            #print(values)

        print(len(ops))
        for a, b, c in ops:
            print("{} {} {}".format(a, b, c))
