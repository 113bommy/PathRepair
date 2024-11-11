#!/usr/bin/python3

n = int(input())

A = list(map(int, input().split()))

print(max(max(A), (2 * sum(A) + n) // n))
