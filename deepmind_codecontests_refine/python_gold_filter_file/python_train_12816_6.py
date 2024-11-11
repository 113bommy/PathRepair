#!/usr/bin/env python3
import math

from typing import Dict, List, Tuple


def input_lst() -> List[int]:
    return [int(x) for x in input().split()]

def print_out(res: List[int]):
    print(' '.join([str(x) for x in res]))

def get_primes(n: int) -> List[int]:
    #max_n = int(n**0.5)
    max_n = n
    rng = list(range(max_n+1))
    rng[0] = 1
    rng[1] = 1
    primes = []
    for i in range(2, max_n+1):
        if rng[i] > 1:
            primes.append(i)
            for j in range(i + i, max_n+1, i):
                rng[j] = 0

    return primes


def main():
    n, m  = (int(x) for x in input().split())

    a = input_lst()

    block_count = sum(a)
    m = max(a)
    min_block_count = n

    sorted_a = sorted(a)[::-1]
    #print(sorted_a)

    cur_block_height = m
    for el in sorted_a:
        if el < cur_block_height:
            min_block_count+=(cur_block_height - el)
            cur_block_height = el
        if cur_block_height > 0:
            cur_block_height -= 1
    #print(block_count, min_block_count, cur_block_height)
    block_to_delete = block_count - (min_block_count + cur_block_height)
    print(block_to_delete)












    #a = input_lst()





if __name__ == '__main__':
    main()
