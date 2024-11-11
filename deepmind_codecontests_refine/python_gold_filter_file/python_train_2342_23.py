class Solution:
    def __init__(self):
        self.n = int(input())
        self.x = [int(xi) for xi in input().split()]

    def solve_and_print(self):
        print(f'{self.x[1] - self.x[0]} {self.x[-1] - self.x[0]}')
        for i in range(1, self.n - 1):
            print(f'{min(self.x[i+1] - self.x[i], self.x[i] - self.x[i-1])} '
                f'{max(self.x[-1] - self.x[i], self.x[i] - self.x[0])}')
        print(f'{self.x[-1] - self.x[-2]} {self.x[-1] - self.x[0]}')

if __name__ == "__main__":
    Solution().solve_and_print()