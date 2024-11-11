class Code:
    def __init__(self):
        self.row = []
        self.matrix = [[1] * 3 for _ in range(3)]
        for _ in range(3):
            self.row.append(list(map(int, input().split())))

    def process(self):
        for i in range(3):
            for j in range(3):
                if self.row[i][j] % 2 == 1:
                    self.matrix[i][j] = (self.matrix[i][j] + 1) % 2
                    if j < 2:
                        self.matrix[i][j + 1] = (self.matrix[i][j + 1] + 1) % 2
                    if j > 0:
                        self.matrix[i][j - 1] = (self.matrix[i][j - 1] + 1) % 2
                    if i < 2:
                        self.matrix[i + 1][j] = (self.matrix[i + 1][j] + 1) % 2
                    if i > 0:
                        self.matrix[i - 1][j] = (self.matrix[i - 1][j] + 1) % 2
        for row in self.matrix:
            print(*row, sep='')


if __name__ == '__main__':
    code = Code()
    code.process()
