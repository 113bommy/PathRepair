# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
mx = -10 ** 10
mix = 10 ** 10
my = mx
miy = mix
for _ in range(int(input())):
    a, b = map(int, input().split())
    mx = max(mx, a)
    mix = min(mix, a)
    my = max(my, b)
    miy = min(miy, b)
ans = max(mx - mix, my - miy)
print(ans * ans)

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
