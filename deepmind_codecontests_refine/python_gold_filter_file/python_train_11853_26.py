H, W = map(int, input().split())

print('#' * (W + 2))
for i in range(H):
    print('#%s#' % (input()))
print('#' * (W + 2))