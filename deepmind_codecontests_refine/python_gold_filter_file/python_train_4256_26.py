N = int(input())
list_input = sorted(map(int, input().split()))
print(sum(list_input[::2]))