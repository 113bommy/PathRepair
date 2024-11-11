#coding: utf-8
X, A, B = map(int, input().split())
print(["delicious", "safe", "dangerous"][(A < B) + (A + X < B)])