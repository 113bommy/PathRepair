if __name__ == '__main__':
    num_rounds = int(input())
    a_r, a_s, a_p = [int(i) for i in input().split()]
    b_r, b_s, b_p = [int(i) for i in input().split()]

    max_win = min(a_r, b_s) + min(a_s, b_p) + min(a_p, b_r)

    # Calculate minimum wins
    min_win = max(a_r - (b_r + b_p), a_p - (b_p + b_s), a_s - (b_s + b_r), 0)
    print(f"{min_win} {max_win}")
